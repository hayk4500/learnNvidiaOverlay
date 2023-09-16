#pragma once
#include "../logger/logger.h"
#include "../overlay/overlay.h"

#include <stdio.h>
#include <dwmapi.h> 
#include <d2d1.h>
#include <dwrite.h>
#pragma comment(lib, "Dwrite") // пока хз что за прагма коммент, не думаю что это так прям важно

#pragma comment(lib, "Dwmapi.lib") 
#pragma comment(lib, "d2d1.lib")


namespace renderer { // неймспейс рендерер
	namespace internal { // вложенный нейспейс интернал в рендере
		inline ID2D1Factory* m_d2d; // создается переменная которая имеет тип этот фабрики, как я понимаю это прост опеременная для инициализации фабрики отрисовки от директа
		inline ID2D1HwndRenderTarget* m_render_target; // создает обьект этого типа как я понимаю это цель для рисовки графики
		inline IDWriteFactory* m_factory; // создает интерфейс с этим названием переменной для фабрики визуалов

		utils::e_status init( ); // обьявление функции инита
		utils::e_status shutdown( ); // обьявление функции шутдауна
	}
}
