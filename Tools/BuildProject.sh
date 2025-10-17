#!/bin/bash

#############################################
# 🔧 CONFIGURATION
#############################################

# Your .uproject file
UPROJECT_NAME="Cortex"

# Build target: Game or Editor
TARGET="Editor"

# Build configuration: Development, DebugGame, Shipping
CONFIGURATION="Development"

# Platform (Mac, Win64, Linux)
PLATFORM="Mac"

# Path to Unreal Engine
UE_PATH="/Users/Shared/Epic Games/UE_5.6"  # Adjust to your UE5 source location

# Auto-resolve actual .uproject file
PROJECT_PATH="$(pwd)/$UPROJECT_NAME.uproject"

#############################################
# 🛠️ FUNCTIONS
#############################################

build_project() {
  echo "🔨 Building $UPROJECT_NAME ($CONFIGURATION $PLATFORM $TARGET)..."

  if [ ! -f "$PROJECT_PATH" ]; then
    echo "❌ Could not find project file: $PROJECT_PATH"
    exit 1
  fi

  "$UE_PATH/Engine/Build/BatchFiles/RunUAT.sh" BuildCookRun \
    -project="$PROJECT_PATH" \
    -build

  if [ $? -ne 0 ]; then
    echo "❌ Build failed!"
    exit 1
  fi

  echo "✅ Build completed successfully."
}

clean_project() {
  echo "🧹 Cleaning build artifacts..."
  rm -rf Binaries Intermediate Saved DerivedDataCache
  echo "✅ Clean complete."
}

show_help() {
  echo ""
  echo "📦 Unreal Engine Build Script"
  echo ""
  echo "Usage:"
  echo "  ./BuildProject.sh [build|clean|help]"
  echo ""
  echo "Defaults:"
  echo "  Project:        $UPROJECT_NAME"
  echo "  Platform:       $PLATFORM"
  echo "  Configuration:  $CONFIGURATION"
  echo "  Engine Path:    $UE_PATH"
  echo ""
}

#############################################
# 🧠 ENTRYPOINT
#############################################

case "$1" in
  build)
    build_project
    ;;
  clean)
    clean_project
    ;;
  help|--help|-h|"")
    show_help
    ;;
  *)
    echo "❌ Unknown command: $1"
    show_help
    exit 1
    ;;
esac
