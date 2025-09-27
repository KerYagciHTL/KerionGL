#!/bin/bash
set -e
if [ -d "glfw" ]; then
  echo "glfw directory already exists, skipping clone."
  exit 0
fi

git clone --depth 1 --branch 3.3-stable https://github.com/glfw/glfw.git glfw