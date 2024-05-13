{ 
  stdenv,
  gcc13,
  glfw,
  glew,
  libGL,
  cglm,
  objects
}: stdenv.mkDerivation {
  name = "cuboid";
  src = ../src;
  nativeBuildInputs = [ gcc13 glfw glew libGL cglm ];
  buildInputs = [ gcc13 glfw glew libGL cglm ];
  buildPhase = ''
    gcc -lglfw -lGLEW -lGL ${builtins.toString objects} -g -o $out
  '';
}
