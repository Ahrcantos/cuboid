{
  stdenv,
  gcc13,
  glfw,
  glew,
  libGL,
  cglm,
  path,
  includes
}: stdenv.mkDerivation {
  name = "obj";
  src = ../src;
  nativeBuildInputs = [ gcc13 glfw libGL cglm glew ];
  buildInputs = [ gcc13 ];
  buildPhase = ''
    gcc -Wall -Wextra -I ${includes} -c ${path} -o $out
  '';
}
