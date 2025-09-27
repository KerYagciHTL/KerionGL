#!/bin/bash
set -e
GLFW_TAG="${GLFW_TAG:-3.3-stable}"
if [ -d "glfw" ]; then
  echo "glfw directory already exists, skipping clone."
  exit 0
fi
git clone --depth 1 --branch "$GLFW_TAG" https://github.com/glfw/glfw.git glfw
