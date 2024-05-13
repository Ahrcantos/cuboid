{
  description = "A basic jumping game";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages."${system}";
    includesDir = pkgs.callPackage ./nix/includes.nix {};
    sourceFiles = [
      ./src/level.c
      ./src/shader.c
      ./src/main.c
      ./src/player.c
    ];
    objects = builtins.map (objPath: pkgs.callPackage ./nix/compileObj.nix {
      path = objPath;
      includes = includesDir;
    }) sourceFiles;
    cuboidBin =  pkgs.callPackage ./nix/compileMain.nix {
      objects = objects;
    };
  in {
    packages.x86_64-linux.default = cuboidBin;
    devShells.x86_64-linux.default = pkgs.mkShell {
      buildInputs = [pkgs.cglm pkgs.glfw pkgs.glew pkgs.libGL pkgs.gcc13 pkgs.xcftools pkgs.imagemagick, pkgs.nixGL];
    };
  };
}
