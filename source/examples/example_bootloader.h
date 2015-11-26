/*

Исходный код Wct Bootloader
Версия 1.0

(c) 2015, Wct Studio
www.wctsite.tk

*/

Lp BP hm	// В регистр SI помещаем адрес сообщения
Pi AL aa	// Вызываем функцию печати строки
Pl OP		// Вечный цикл для корректной работы программы

/* Процедура печати символа (процедура 1) */

Le AP		// Помещаем в регистр AH число AP (15). Объясняем БИОС-у то, 
		// что нам нужно вывести один символ на экран. В регистре AL
		// хранится ASCII значение нашего сообщения
Lh AA		// В регистр BH - 0, соответственно, это и есть номер страницы
Ld AH		// Ну а в регистр BL - 7, это значит, что у нас будет выводиться
		// светло-серый текст на черном фоне

Mn BA		// Как только видим Mn - сразу вспоминаем, что это прерывание
		// На данный момент это прерывание 16 (десятичная система)
		// а в hex - знакомое нам прерывание 0x10.
		// Это прерывание BIOS - видео сервис

Md		// Выходим из процедуры

/* Процедура вывода строки на экран (процедура 2) */

// вывод символа (процедура 3)

Ik AE		// Помещаем в регистр AL значение из SI
Eg		// Инкренмент (увеличение на единицу) регистра SI

Ai MA		// Если значение регистра AL - 0 (т.е. строка закончилась), то
He AF		// заканчиваем выполнение программы (выполнение процедуры 4)
		// - 5 байт вперед на команду Md (выход из программы)

Pi PN oo	// Если же строка не закончилась, то выполняем процедуру 1
		// т.е. выводим символ, который находится в AL

Pl OE           // Берем следующий символ из строки (выполнение процедуры 3)

Md		// Все, закругляемся и выходим из программы

FH GD HE CA	// ASCII: Wct (пробел)
GO GP GF CA 	// 	  one (пробел)
GM GO HG GF	//	  love
Aa		// Конец строки обязан заканчиваться нулем, т.е. Aa :)

/* У нас осталось свободное место, до 512 байт нам нужно написать недостающие Aa (0) */

Aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa aa 
aa aa aa aa aa aa aa

// До 512 байт нам не хватает всего двух байтов..

Ff KK		// FF KK - подпись загрузчика, чтобы компьютер понял,
		// что это загрузчик, и его необходимо загрузить в
		// память. В windows есть подписи "MZ" & "PE", а тут
		// такое вот дело.
