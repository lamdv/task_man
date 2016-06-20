#include <time.h>

class Process
{
	private:
		int p_id;
		time_t time; 
		string CMD;
	public:
		void Process(int p_id, time_t time, string CMD);
        
        #getter
		int get_P_id();
		int get_time();
		int get_CMD();
		
        #setter
		void set_P_id(int p_id);
		void set_time(time_t time);
		void set_CMD(string CMD);
};
