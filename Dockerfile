FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    pkg-config \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libxext-dev \
    libxkbcommon-dev \
    libgl1-mesa-glx \
    libglx0 \
    libglvnd0 \
    && rm -rf /var/lib/apt/lists/*

# Clone and build raylib
RUN git clone https://github.com/raysan5/raylib.git /raylib && \
    cd /raylib/src && \
    make PLATFORM=PLATFORM_DESKTOP && \
    make install PLATFORM=PLATFORM_DESKTOP

# Set working directory
WORKDIR /app

# Copy project files
COPY 3Dobj.c .
COPY suzanne.obj .

# Compile the program
RUN gcc -o main 3Dobj.c -lraylib -lm -lpthread -ldl -lrt -lX11

# Set display for X11 forwarding
ENV DISPLAY=:0

# Run the program
CMD ["./main"]

