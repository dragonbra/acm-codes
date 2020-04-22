int Day(int year, int month, int day){
	int ret = 0;
	int c, y, m, d;
	if(month <= 2){
		c = ( year - 1 ) / 100;
		y = ( year - 1 ) % 100;
		m = month + 12;
		d = day;
	}
	else{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}
	ret = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + d - 1;
	ret = ret >= 0 ? ( ret % 7 ) : ( ret % 7 + 7 );
	return ret;
}
