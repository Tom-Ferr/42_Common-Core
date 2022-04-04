import { Controller, Post, ClassSerializerInterceptor, UseInterceptors, Body, Req, Get, Res} from '@nestjs/common';
import { ConfigService } from '@nestjs/config';
import axios from 'axios';
import * as randomId from 'random-id'
import { UseGuards } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
import { stringify } from 'querystring';
import { AuthenticationService } from '../authentication.service';
import { response } from 'express';
   
@Controller('oauth')
@UseInterceptors(ClassSerializerInterceptor)
export class OAuthController {

    constructor(
        private readonly configService: ConfigService,
        private readonly authenticationService: AuthenticationService,
    ) {}

    @Get('/login')
    async loginIntra(@Res() res) {
    const state = '&state=' + randomId() 
    const redirect_uri = '&redirect_uri=' + this.configService.get('OAUTH_REDIRECT')
    const client_id = '&client_id=' + this.configService.get('OAUTH_ID')
    const tohere = 'https://api.intra.42.fr/oauth/authorize?response_type=code'
    res.send(tohere+state+redirect_uri+client_id);
    }

    @Get('/authenticate')
    async authenticate(@Req() req, @Res() res) {
        const options ={
            grant_type: 'authorization_code',
            code: req.query.code,
            client_id: this.configService.get('OAUTH_ID'),
            client_secret: this.configService.get('OAUTH_SECRET'),
            redirect_uri: this.configService.get('OAUTH_REDIRECT'),
            state: req.query.state,
        }
        let holder
        let user
        await axios.post(`https://api.intra.42.fr/oauth/token?${stringify(options)}`,{}, {headers: {'Content-Type': 'application/x-www-form-urlencoded'}})
        .then(response => holder = response.data)
        .catch(error => console.log(error.response.status, error.response.statusText, '\n', error.response.data.error_description))
        if(!holder)
            return res.redirect(`http://localhost:8080`)
        const {data} = await axios.get('https://api.intra.42.fr/v2/me', {headers: {"Authorization": `Bearer ${holder.access_token}`}})
        try{
            user = await this.authenticationService.getIntraUser(data.login)
        }
        catch (error) {
            user = await this.authenticationService.registerThroughOAuth(data.login)
        }
        if(user){
            const cookie = this.authenticationService.getCookieWithJwtToken(user.id);
            res.setHeader('Set-Cookie', cookie);
            if(user.name)
                return res.redirect(`http://localhost:8080/logged`)
            return res.redirect(`http://localhost:8080/register`)
                
        }
        res.redirect(`http://localhost:8080`)
    }
}

