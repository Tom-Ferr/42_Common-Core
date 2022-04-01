/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posts.controller.ts                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:06 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:25:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Body, Controller, Delete, Get, Param, Post, Put, UseGuards } from '@nestjs/common';
import PostsService from './posts.service';
import {CreatePostDto} from './dto/createPost.dto';
import {UpdatePostDto} from './dto/updatePost.dto';
import { JwtAuthenticationGuard } from '../authentication/jwt-authentication.guard';
import FindOneParams from 'src/utils/findOneParams';
import JwtTwoFactorGuard from 'src/authentication/jwt-two-factor.guard';

@Controller('posts')
export default class PostsController {
  constructor(
    private readonly postsService: PostsService
  ) {}

  @Get()
  getAllPosts() {
    return this.postsService.getAllPosts();
  }

  @Get(':id')
  getPostById(@Param() { id }: FindOneParams) {
    return this.postsService.getPostById(Number(id));
  }
 
  @Post()
  @UseGuards(JwtTwoFactorGuard)
  async createPost(@Body() post: CreatePostDto) {
    return this.postsService.createPost(post);
  }
  
 
  @Put(':id')
  async replacePost(@Param('id') id: string, @Body() post: UpdatePostDto) {
    return this.postsService.updatePost(Number(id), post);
  }
 
  @Delete(':id')
  async deletePost(@Param('id') id: string) {
    this.postsService.deletePost(Number(id));
  }
}
