#!/bin/bash

# Colors for better output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Build function
build_and_run() {
    echo -e "${BLUE}============================================${NC}"
    echo -e "${YELLOW}🔄 Change detected! Rebuilding project...${NC}"
    echo -e "${BLUE}============================================${NC}"
    
    # Remove old build
    if [ -d "build" ]; then
        echo -e "${YELLOW}🗑️  Removing old build directory...${NC}"
        rm -rf build
    fi
    
    # Create build directory
    echo -e "${YELLOW}📁 Creating build directory...${NC}"
    mkdir build
    cd build
    
    # Configure with CMake
    echo -e "${YELLOW}⚙️  Configuring with CMake...${NC}"
    if cmake ..; then
        echo -e "${GREEN}✅ CMake configuration successful${NC}"
    else
        echo -e "${RED}❌ CMake configuration failed${NC}"
        cd ..
        return 1
    fi
    
    # Build
    echo -e "${YELLOW}🔨 Building project...${NC}"
    if make -j$(nproc); then
        echo -e "${GREEN}✅ Build successful!${NC}"
    else
        echo -e "${RED}❌ Build failed${NC}"
        cd ..
        return 1
    fi
    
    echo -e "${GREEN}🚀 Starting ProcessMonitor server...${NC}"
    echo -e "${BLUE}============================================${NC}"
    
    if [ -f "./ProcessMonitorBackend" ]; then
        ./ProcessMonitorBackend
    elif [ -f "./backend/ProcessMonitorBackend" ]; then
        ./backend/ProcessMonitorBackend
    elif [ -f "./src/ProcessMonitorBackend" ]; then
        ./src/ProcessMonitorBackend
    else
        echo -e "${RED}❌ Could not find ProcessMonitorBackend executable${NC}"
        echo -e "${YELLOW}Looking for executable in build directory...${NC}"
        find . -name "ProcessMonitorBackend" -type f -executable
        cd ..
        return 1
    fi
    
    cd ..
}

export -f build_and_run
export RED GREEN YELLOW BLUE NC

echo -e "${GREEN}👀 Starting file watcher with entr...${NC}"
echo -e "${YELLOW}Watching: src/, backend/, include/ directories${NC}"
echo -e "${YELLOW}File types: *.cpp, *.h, *.hpp${NC}"
echo -e "${BLUE}Press Ctrl+C to stop${NC}"
echo ""

find src backend include main.cpp -name "*.cpp" -o -name "*.h" -o -name "*.hpp" 2>/dev/null | entr -rc bash -c 'build_and_run'