FROM node:alpine
RUN npm install -g @nestjs/cli
WORKDIR /server
COPY ./ ./
RUN npm install
EXPOSE 3000
ENTRYPOINT ["npm", "start"]