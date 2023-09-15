#pragma once


namespace utils { // какое-то пространство имЄт утилса
	enum class e_status : int { // «десь начинаетс€ перечисление класса е статусов
		status_ok = 0, // статус ок
		status_failed // статус фейла
	};

	inline bool operator! ( e_status e ) { //как € понимаю тут оператор перегрузки восклицательного знака ! 
 		return e == e_status::status_failed; // который возвращает е как статус фейла, аналогично оператору сравнени€ Ќ≈ как € понимаю
	}
}
