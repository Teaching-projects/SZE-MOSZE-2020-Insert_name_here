FROM ubuntu:20.04


RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
  make \
  cppcheck \
  valgrind \
  gcc \
  g++ \
  gcc-10 \
  g++-10 \
  libgtest-dev \
  cmake \
  doxygen \
  graphviz \
  git \
&& rm -rf /var/lib/apt/lists/*
