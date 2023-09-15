#ifdef _DEBUG
#define LOG_DEBUG_MESSAGES
#endif

#include "scene.h"


utils::e_status init( ) { // начало функции инита
	TRACE_FN; // слежение какое-то, дебаг чтоль хз, короче это чтобы логгер все записывал

	L_ASSERT( overlay::init( ), "failed to initialize overlay" ); // ассертится функция инита оверлея, выводить ошибку тип или нет если инит НЕ произошёл
	logger::info( "Initialized overlay" ); // если все успешно, то выводит это сообщение (если прошлое ассерт не применился).

	L_ASSERT( renderer::init( ), "failed to initialize renderer" ); // ассерт функции инита рендера, если будет нуль, то выведет это сообщение
	logger::info( "Initialized renderer" );

	return utils::e_status::status_ok;
}


utils::e_status shutdown( ) {
	TRACE_FN;

	L_ASSERT( renderer::shutdown( ), "failed to shut down renderer" );
	logger::info( "Shut down renderer" );

	return utils::e_status::status_ok;
}


int main( ) {
	TRACE_FN; // слежение какое-то, дебаг чтоль хз, короче это чтобы логгер все записывал

	if ( !init( ) ) return -1; // Если не инит, то возвращает единицу
	if ( !show_scene( ) ) return -1;
	if ( !shutdown( ) ) return -1;

	return 0;
}