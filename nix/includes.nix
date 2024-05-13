{ stdenv }: stdenv.mkDerivation {
  name = "includes";
  src = ../src;
  buildInputs = [];
  buildPhase = ''
    mkdir -p $out/cuboid
    cp ./level.h $out/cuboid
    cp ./shader.h $out/cuboid
    cp ./player.h $out/cuboid
  '';
}
