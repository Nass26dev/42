FROM debian:bullseye

RUN apt update ; \
    apt install nginx -y ; \
    apt install openssl -y && \
    apt clean

RUN 

CMD ["nginx", "-g", "daemon off;"]
