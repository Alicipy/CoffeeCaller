#!/bin/bash

# SPDX-FileCopyrightText: 2025 andreaskurz
#
# SPDX-License-Identifier: Apache-2.0

WORKSPACE_DIR=$1
REPO_NAME=$2

cd $WORKSPACE_DIR

# Adjust permissions as docker volumes is owned by root
sudo chown -R $(id -g):$(id -u) $WORKSPACE_DIR

# Init west workspace if not present
if [ ! -d ".west" ]; then
    west init -l $REPO_NAME
fi

if [ ! -f .clangd ]; then
    ln -s $REPO_NAME/.devcontainer/.clangd
fi

if [ ! -f .clang-format ]; then
    ln -s zephyr/.clang-format
fi

# Fetch upstream modules and setup tools
west update

pip3 install --upgrade --requirement zephyr/scripts/requirements.txt
