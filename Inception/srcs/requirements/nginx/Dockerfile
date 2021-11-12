FROM alpine:3.13
RUN apk update
RUN apk add nginx
RUN apk add openssl
RUN mkdir -p /run/nginx
RUN openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=tde-cama.42.fr" -addext "subjectAltName=DNS:tde-cama.42.fr" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt;
COPY ./default.conf /etc/nginx/http.d/default.conf
EXPOSE 443
ENTRYPOINT ["nginx", "-g", "daemon off;"]
