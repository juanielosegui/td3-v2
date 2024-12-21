#include <gtest/gtest.h>
#include "resaltador.h"
#include <set>
#include <string>

using namespace std;

TEST(resaltador_tests,test_nuevo_resaltador) {
  Resaltador r;

  ASSERT_EQ(r.categorias().size(),0);
  ASSERT_EQ(r.palabras_resaltables().size(),0);
}

TEST(resaltador_tests,test_definir_categoria) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  ASSERT_EQ(r.categorias(),set<string>({"cat1"}));
  ASSERT_EQ(r.color_categoria("cat1"),1);
}

TEST(resaltador_tests,test_asignar_categoria) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  r.asignar_categoria("for","cat1");
  ASSERT_EQ(r.categoria_de_palabra("for"),"cat1");
  ASSERT_EQ(r.palabras_resaltables(),set<string>({"for"}));
  ASSERT_EQ(r.color_resaltado("for"),1);
}

TEST(resaltador_tests,test_desasignar_categoria) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  r.asignar_categoria("for","cat1");
  ASSERT_EQ(r.categoria_de_palabra("for"),"cat1");

  r.desasignar_palabra("for");
  ASSERT_EQ(r.es_resaltable("for"),false);
  ASSERT_EQ(r.palabras_resaltables().size(),0);
}

TEST(resaltador_tests,test_desasignar_ultima_palabra_no_borra_categoria) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  r.asignar_categoria("for","cat1");
  r.desasignar_palabra("for");
  ASSERT_EQ(r.categorias(),set<string>({"cat1"}));
}

TEST(resaltador_tests,test_borrar_categoria) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  r.borrar_categoria("cat1");
  ASSERT_EQ(r.categorias().size(),0);
}

TEST(resaltador_tests,test_borrar_categoria_borra_palabras) {
  Resaltador r;

  r.definir_categoria("cat1",1);
  r.asignar_categoria("for","cat1");
  r.asignar_categoria("if","cat1");
  r.borrar_categoria("cat1");
  ASSERT_EQ(r.categorias().size(),0);
  ASSERT_EQ(r.palabras_resaltables().size(),0);
  ASSERT_EQ(r.es_resaltable("for"),false);
  ASSERT_EQ(r.es_resaltable("if"),false);
}

TEST(resaltador_tests,test_cargar_sintaxis_vacia_pisa_existentes) {
  Resaltador r;

  r.definir_categoria("prueba",1);
  r.asignar_categoria("hola","prueba");
  
  r.cargar_sintaxis("sintaxis-nula.txt");
  ASSERT_EQ(r.palabras_resaltables(),set<string>({}));
  ASSERT_EQ(r.categorias(),set<string>({}));
}

TEST(resaltador_tests,test_cargar_sintaxis) {
  Resaltador r;

  r.cargar_sintaxis("sintaxis-cpp.txt");
  ASSERT_EQ(r.categorias(),set<string>({"keywords","tipos_basicos","separadores","operadores", "comentarios"}));
  ASSERT_EQ(r.palabras_resaltables(),set<string>({"if", "then", "else", "for", "using", "namespace", "#include",
                                                 "int", "float", "double", "bool", "unsigned", "void", "char", "char*", "char**",
                                                 "{", "}", "[", "]", "(", ")", ";",
                                                 "+", "-", "*", "/", "%", "==", "!=",
                                               "//","/*", "*/"}));
  ASSERT_EQ(r.color_categoria("keywords"),2);
  ASSERT_EQ(r.color_categoria("tipos_basicos"),3);
  ASSERT_EQ(r.color_categoria("separadores"),4);
  ASSERT_EQ(r.color_categoria("operadores"),5);
  ASSERT_EQ(r.color_categoria("comentarios"),6);
}
