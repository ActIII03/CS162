#Image GCC
FROM gcc:latest

RUN apt-get update && apt-get install -y gdb
RUN /bin/bash uname -a


