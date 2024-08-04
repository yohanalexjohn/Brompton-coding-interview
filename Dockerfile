FROM ubuntu:latest

LABEL key="value"

RUN apt-get update && apt-get install -y \
    xdg-utils \
    build-essential \
    cmake \
    make \
    doxygen \
    git \
    curl \
    && apt-get clean

# Set up directories
WORKDIR /brompton

# Copy your project files
COPY . .
