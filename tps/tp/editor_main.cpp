#include "editor_texto.h"
#include "ui.hpp"

using namespace std;

int main(int argc, char** argv) {
  EditorSintaxis editor;
  if (argc==3){
    editor.cargar_texto(argv[1]);
    editor.cargar_sintaxis(argv[2]);
  }
  UI(editor).ejecutar();
}
