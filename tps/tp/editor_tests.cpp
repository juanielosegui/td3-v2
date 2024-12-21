#include <cassert>
#include <gtest/gtest.h>
#include <string>

#include "editor_texto.h"

using namespace std;

TEST(editor_tests,test_nuevo_editor) {
  EditorSintaxis e;
  ASSERT_EQ(e.longitud(),0);
  ASSERT_EQ(e.resaltador().categorias().size(),0);
  ASSERT_EQ(e.resaltador().palabras_resaltables().size(),0);
}

TEST(editor_tests,test_insertar_palabra) {
  EditorSintaxis e;
  e.insertar_palabra("mundo", 0);
  e.insertar_palabra("hola", 0);

  ASSERT_EQ(e.palabra_en(0),"hola");
  ASSERT_EQ(e.palabra_en(1),"mundo");

  e.insertar_palabra("lindo",1);
  
  ASSERT_EQ(e.palabra_en(0),"hola");
  ASSERT_EQ(e.palabra_en(1),"lindo");
  ASSERT_EQ(e.palabra_en(2),"mundo");
  ASSERT_EQ(e.longitud(),3);

  e.insertar_palabra("chau",3);
  ASSERT_EQ(e.palabra_en(3),"chau");
}

TEST(editor_tests,test_con_texto) {
  EditorSintaxis e = EditorSintaxis::con_texto("hola mundo chau");

  ASSERT_EQ(e.longitud(),3);
  ASSERT_EQ(e.palabra_en(0),"hola");
  ASSERT_EQ(e.palabra_en(1),"mundo");
  ASSERT_EQ(e.palabra_en(2),"chau");
}

TEST(editor_tests,test_cargar_texto) {
  EditorSintaxis e;
/* texto:
2
keywords 2 4
if then else for
otros 4 3
hola como va
*/
  e.cargar_texto("sintaxis.txt");
  int i = 0;
  ASSERT_EQ(e.palabra_en(i++),"2");
  ASSERT_EQ(e.palabra_en(i++),"keywords");
  ASSERT_EQ(e.palabra_en(i++),"2");
  ASSERT_EQ(e.palabra_en(i++),"4");
  ASSERT_EQ(e.palabra_en(i++),"if");
  ASSERT_EQ(e.palabra_en(i++),"then");
  ASSERT_EQ(e.palabra_en(i++),"else");
  ASSERT_EQ(e.palabra_en(i++),"for");
  ASSERT_EQ(e.palabra_en(i++),"otros");
  ASSERT_EQ(e.palabra_en(i++),"4");
  ASSERT_EQ(e.palabra_en(i++),"3");
  ASSERT_EQ(e.palabra_en(i++),"hola");
  ASSERT_EQ(e.palabra_en(i++),"como");
  ASSERT_EQ(e.palabra_en(i++),"va");
}

TEST(editor_tests,test_cargar_sintaxis) {
  EditorSintaxis e;
  e.cargar_sintaxis("sintaxis.txt");
  ASSERT_EQ(e.resaltador().categorias(),set<string>({"keywords","otros"}));
  ASSERT_EQ(e.resaltador().palabras_resaltables(),set<string>({"if","then","else","for","hola","como","va"}));
}

TEST(editor_tests,test_cargar_sintaxis_posiciones_categorias) {
  EditorSintaxis e = EditorSintaxis::con_texto("if then else for hola como va");
  e.cargar_sintaxis("sintaxis.txt");

  ASSERT_EQ(e.posiciones_de_categoria("keywords"),set<int>({0,1,2,3}));
  ASSERT_EQ(e.posiciones_de_categoria("otros"),set<int>({4,5,6}));   
}

 TEST(editor_tests,test_insertar_palabra_actualiza_posiciones) {
  EditorSintaxis e = EditorSintaxis::con_texto("if then else for hola como va");
  e.cargar_sintaxis("sintaxis.txt");

  e.insertar_palabra("if",e.longitud());
  e.insertar_palabra("hola",e.longitud());

  ASSERT_EQ(e.posiciones_de_categoria("keywords"),set<int>({0,1,2,3,7}));
  ASSERT_EQ(e.posiciones_de_categoria("otros"),set<int>({4,5,6,8}));   
}

TEST(editor_tests,test_borrar_palabra_actualiza_posiciones) {
  EditorSintaxis e = EditorSintaxis::con_texto("if then else for hola como va");
  e.cargar_sintaxis("sintaxis.txt");

  e.borrar_palabra(0);
  e.borrar_palabra(5);

  ASSERT_EQ(e.posiciones_de_categoria("keywords"),set<int>({0,1,2}));
  ASSERT_EQ(e.posiciones_de_categoria("otros"),set<int>({3,4}));   
}

TEST(editor_tests,test_cargar_nueva_sintaxis_actualiza_posiciones) {
  
  EditorSintaxis e = EditorSintaxis::con_texto("if then else for hola como va");
  e.cargar_sintaxis("sintaxis.txt");

  ASSERT_EQ(e.posiciones_de_categoria("keywords"),set<int>({0,1,2,3}));
  ASSERT_EQ(e.posiciones_de_categoria("otros"),set<int>({4,5,6}));   
  
  e.cargar_sintaxis("sintaxis-b.txt");

  ASSERT_EQ(e.posiciones_de_categoria("cat1"),set<int>({0,2,3,6}));
  ASSERT_EQ(e.posiciones_de_categoria("cat2"),set<int>({1,4,5}));   
}

// TEST(editor_tests,test_) {
  
// }


