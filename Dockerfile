#Image GCC
FROM gcc:latest

RUN apt-get update && \
    apt-get upgrade \
    && apt-get install -y gdb

ADD /home/armant

WORKDIR /home/armant

VOLUME /files

