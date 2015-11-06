#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std; // Sabe Tudo Doido
using namespace sf; // Se Fudeu

int main() {
    RenderWindow janelis;
    Texture textura;
    Sprite isprito;

    janelis.create(VideoMode(640, 480), L"Relou Uôrdi");

    if (!textura.loadFromFile("hello.png")) {
        cout << "Não foi possível carregar a textura\n";
        return 1;
    }
    isprito.setTexture(textura);

    Event evento;
    bool correndoFeitoDoido = true;
    while (correndoFeitoDoido) {
        while (janelis.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                correndoFeitoDoido = false;
            }
        }

        janelis.clear(Color::Black);
        janelis.draw(isprito);
        janelis.display();
    }


    janelis.close();

    return 0;
}