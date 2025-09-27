#!/usr/bin/env bash
set -euo pipefail

: "${GLFW_TAG:=3.3-stable}"

cd "$(dirname "$0")"

if [[ -d glfw/.git ]]; then
  echo "[prepare] glfw already present -> skip clone"
  exit 0
fi

echo "[prepare] cloning GLFW tag '${GLFW_TAG}'"
git clone --depth 1 --branch "${GLFW_TAG}" https://github.com/glfw/glfw.git glfw
echo "[prepare] done"
