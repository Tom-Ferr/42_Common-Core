/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posts.service.ts                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:10 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:25:11 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import {CreatePostDto} from './dto/createPost.dto';
// import {Post} from './post.interface';
import {UpdatePostDto} from './dto/updatePost.dto';
import { InjectRepository } from '@nestjs/typeorm';
import Post from './post.entity'
import { Repository, In } from 'typeorm';
import postNotFound from './exception/postNotFund.exception'

@Injectable()
export default class PostsService {
  private lastPostId = 0;
  private posts: Post[] = [];

  constructor(
    @InjectRepository(Post)
    private postsRepository: Repository<Post>
  ) {}
 
  getAllPosts() {
    return this.postsRepository.find();
  }
 
  async getPostById(id: number) {
    const post = await this.postsRepository.findOne(id);
    if (post) {
      return post;
    }
    throw new postNotFound(id);
  }

  async updatePost(id: number, post: UpdatePostDto) {
    await this.postsRepository.update(id, post);
    const updatedPost = await this.postsRepository.findOne(id);
    if (updatedPost) {
      return updatedPost
    }
    throw new postNotFound(id);
  }
 
  async createPost(post: CreatePostDto) {
    const newPost = await this.postsRepository.create(post);
    await this.postsRepository.save(newPost);
    return newPost;
  }
 
  async deletePost(id: number) {
    const deleteResponse = await this.postsRepository.delete(id);
    if (!deleteResponse.affected) {
      throw new postNotFound(id);
    }
  }
}