/**
 * @file Application.h
 * @brief plik zawiekaj�cy klase Application
 */

#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Mouse.h"
#include "Block.h"
#include "Block.cpp"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Brush.h"
#include "DrawableObject.h"


 /** Klasa obiektu aplikacji*/
class Application
{
private:
	sf::RenderWindow window; ///< Obiekt okna
	Mouse mouse; ///< obiekt myszki
public:
	/** Konstruktor klasy Application
	 * @param windowWidth szeroko�� okna
	 * @param windowHeight wysoko�� okna
	 * @param filename nazwa pliku do kt�rego ma si� zapisa� praca
	 */
	Application(const int& windowWidth = 800, const int& windowHeight = 400, const std::string& filename = "Paint");
	
	/** Dekonstruktor klasy Application */
	~Application();

	/** Funkcja kt�ra uruchamia program */
	void run();
	
	bool isLeftButtonPressed; ///< zmienna m�wi�ca czy lewy przycisk myszki jest naci�ni�ty
	bool isShiftPressed; ///< zmienna m�wi�ca czy przycisk Shift jest naci�ni�ty
	bool isControlPressed; ///< zmienna m�wi�ca czy przycisk Control jest naci�ni�ty
	bool isZPressed; ///< zmienna m�wi�ca czy przycisk Z jest naci�ni�ty
	bool isYPressed; ///< zmienna m�wi�ca czy przycisk Y jest naci�ni�ty
	bool isSceneChanged; ///< zmienna m�wi�ca czy scena si� zmieni�a
	bool isSPressed; ///< zmienna m�wi�ca czy przycisk S jest naci�ni�ty
	bool toDraw;  ///< zmienna m�wi�ca czy mo�na kontynu�owa� rysowanie nast�pnego obiektu
	bool ColorChanged; ///< zmienna m�wi�ca czy kolor si� zmieni�
	bool outLineIsSet; ///< zmienna m�wi�ca czy obramowanie jest ustawione
	bool doSave; ///< zmienna m�wi�ca czy nale�y zapisa� aktualn� scene
	std::string filename; ///< nazwa pliku
	sf::Text thicknessText; ///< tekst m�wi�cy o aktualnej grubo�ci
	sf::Font font; ///< czcionka
	std::vector<BaseBlock*> allBlockObject = {}; ///<  wektor wzka�niki do obiekt�w bloku
	std::vector<DrawableObject*> allDrawableObjects = {}; ///<  wektor wzka�niki do obiekt�w do narysowania
	std::vector< DrawableObject*> allObjectsInClipboard = {}; ///<  wektor wzka�niki do obiekt�w w schowku
	std::vector<sf::Texture> allTextures; ///<  wektor zawieraj�cy wszystkie tekstury

private:
	/** Funkcja obs�ugi zdarze� */
	void events();

	/** Funkcja kt�ra aktualizuje wszytkie obiekty
	 * @param window okno do rysowania
	 */
	void updateAll(sf::RenderWindow& window);

	/** Funkcja kt�ra rysuje wszystkie obiekty na oknie  
	 * @param window okno do rysowania
	 */
	void drawAll(sf::RenderWindow& window);
	/** Funkcja aktualizuj�ca schowek */
	void updateClipboard();
	/** Funkcja usuwaj�ca schowek */
	void clearClipboard();
	/** Funkcja sprawdzaj�ca czy nale�y zapisa� */
	void saveFile();
	/** Funkcja tworz�ca wszystkie pocz�tkowe obiekty */
	void createEverything();
	/** Funkcja kt�ra tworzy nowe obiekty na oknie */
	void drawFunction();
	/** Funkcja kt�ra sprawdza czy obiekt jest klikni�ty, je�li tak to jest wykonywana odpowiednia operacja */
	void isBlockClicedFunction();
};

