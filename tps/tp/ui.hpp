#pragma once

#include "editor_texto.h"
#include "resaltador.h"

#include <iostream>
#include <sstream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

using namespace std;
using namespace ftxui;

class UI {
  public:
    UI(EditorSintaxis & editor) : _editor(editor), _pos(0), _reset_position(""), _screen(Screen::Create(Dimension::Full(), Dimension::Full())) {};

    void ejecutar() {
      while(true) {
        render();
        ejecutar_comando();
      }
    }

  private:
    EditorSintaxis _editor;
    int _pos;

    string _reset_position;
    Screen _screen;

    void ejecutar_comando() {
      string tmp, tmp2;
      int desde, hasta;

      char ch;
      cin >> ch;
      switch(ch) {
        case 'q':
          exit(0); break;
        case 'i': {
          getline(cin,tmp);
          stringstream ss(tmp);
          while (ss >> tmp2)
            _editor.insertar_palabra(tmp2,_pos++);
        } break;
        case 'e':
          if (_pos < _editor.longitud())
            _editor.borrar_palabra(_pos);
          break;
        case 'c':
          cin >> tmp;
          _editor.cargar_sintaxis(tmp);
          break;
        case 'f':
          cin >> tmp;
          _editor.cargar_texto(tmp);
          _pos = 0;
          break;
        case 'C':
          for (auto c: _editor.resaltador().categorias())
            cout << c << " ";
          cout << endl << "[c]ontinuar...";
          cin >> ch;
          break;
        case 'P':
          cout << "categoria?:";
          cin >> tmp;
          if (_editor.resaltador().categorias().count(tmp)== 0) {
            cout << "CATEGORIA INEXISTENTE";
          } else {
          cout << "posiciones de "<<tmp<<": { ";   
          for (auto pos: _editor.posiciones_de_categoria(tmp))
            cout << pos << " ";
          }
          cout << "}";
          cout << endl << "[c]ontinuar...";            
          cin>>ch;
          break;
        case 'r':
          break;
        case 'h':
          _pos = (_pos-1) % (_editor.longitud()+1);
          break;
        case 'l':
          _pos = (_pos+1) % (_editor.longitud()+1);
        default:
          break;
      }
    }

    void render() {
      stringstream status_posicion, instrucciones, ft;
      std::vector<Element> palabras;
      status_posicion    << "Posición: " << _pos << " de " << _editor.longitud();
      instrucciones      << "Comandos: [i]nsertar y [e]liminar palabra, [c]argar <sintaxis>, [h/l] mover a der/izq, [f] cargar <texto>, ver [C]ategorias, ver [P]osiciones de <categoría> " << endl;

      for (int i=0; i < _editor.longitud(); ++i) {
        stringstream txt;
        if (_pos == i) txt << "[";
        txt << _editor.palabra_en(i);
        if (_pos == i) txt << "]";
        txt << " ";

        if(_editor.resaltador().es_resaltable(_editor.palabra_en(i))) {
          palabras.push_back(text(txt.str()) | bgcolor(Color::White) | color(Color((Color::Palette16) _editor.resaltador().color_resaltado(_editor.palabra_en(i)))));
        } else {
          palabras.push_back(text(txt.str()) | bgcolor(Color::White) | color(Color((Color::Palette16) 0)));
        }
      }

      if (_pos == _editor.longitud()) {
        palabras.push_back(text(">"));
      }

      auto document = vbox({
        vbox({
          text(status_posicion.str()),
        }),
        hflow(palabras) | border | flex | bgcolor(Color::White),
        hflow(paragraph(instrucciones.str())),
      });

      _screen.Clear();
      Render(_screen, document);

      cout << _reset_position;
      _screen.Print();
      _reset_position = _screen.ResetPosition();
    }
};
