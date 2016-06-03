#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include <list>
#include <string>
#include <map>

class Main;

class Board
{
public:
	typedef struct Date {
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
	} Date;

	Board( Main* main );
	~Board();

	static std::string infos();

	static void InformLoading( int force_led = -1 );
	static void LoadingDone();

	static void setLocalTimestamp( uint32_t t );
	static Date localDate();

	static const std::string LoadRegister( const std::string& name );
	static int SaveRegister( const std::string& name, const std::string& value );

	static uint64_t GetTicks();
	static uint64_t WaitTick( uint64_t ticks_p_second, uint64_t lastTick, uint64_t sleep_bias = -500 );

	static uint32_t CPULoad();
	static uint32_t CPUTemp();
	static std::string readcmd( const std::string& cmd, const std::string& entry = "", const std::string& delim = ":" );

private:
	static uint64_t mTicksBase;
	static std::map< std::string, std::string > mRegisters;
};

#endif // BOARD_H
