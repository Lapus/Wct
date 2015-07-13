/*

DOS-ЗАГОЛОВОК
показывает, что это двоичный формат исполняемого файла

*/


EN FK // сигнатура MZ указывает на то, что наш файл будет исполняться в Windows. Для перевода букв в ASCII коды на Wct есть таблица - www.wctsite.tk/table

AA AA AA AA AA AA AA AA // Пустые байты
AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA
AA AA

EA AA AA AA // смещение PE заголовка указывает на то, где начинается PE заголовок

/*

PE-ЗАГОЛОВОК
указывает на то, что это современный исполняемый файл

*/

FA EF // "PE" (указывает на то, что это PE заголовок)
AA AA // постоянная сигнатура (0,0)

EM AB // указывает на то, что наша архитектура i8086

AD AA // кол-во секций (переводим 3 в Wct = ad)

AA AA AA AA // пустое заполнение
AA AA AA AA
AA AA AA AA

PA AA // относительное смещение таблицы RVA секций (по адресу 0xpa)

AC AB // наш файл является 32-битным исполняемым EXE

/*

ОПЦИОНАЛЬНЫЙ ЗАГОЛОВОК
информация об исполняемом файле

*/

AL AB // "Магическое число", указывает на то, что программа у нас 32-х битная

AA AA AA AA // пустой наполнитель
AA AA AA AA
AA AA AA AA
AA AA

AA BA AA AA // адрес RVA точки входа в программу

AA AA AA AA // пустые байты
AA AA AA AA

AA AA EA AA // предпочтительный адрес в памяти, куда следует "проецировать" файл

AA BA AA AA // адреса секций в памяти будут "выравниваться" по этому значению
AA AC AA AA // смещение секций ^

AA AA AA AA // тут даже ничего говорить не надо
AA AA AA AA

AE AA // необходимая версия Windows (NT 4 и более)

AA AA AA AA // пусто
AA AA

AA EA AA AA // необходимый объем памяти для загрузки файла в память
AA AC AA AA // размер всех заголовков (200h - CAAw)

AA AA AA AA // пустые байты

AC AA // тип подсистемы (Bw = драйвер, Cw = GUI, Dw = консоль...)

AA AA AA AA // я просто промолчу..
AA AA AA AA 
AA AA AA AA
AA AA AA AA 
AA AA AA AA 
AA AA

BA AA AA AA // кол-во директорий данных (Baw = 16)

/*

ДИРЕКТОРИИ ДАННЫХ
указатели на дополнительные структуры (экспорт, импорт, ...)

*/

AA AA AA AA // хорошее начало..
AA AA AA AA

AA CA AA AA // RVA директории импорта

AA AA AA AA AA AA AA AA AA AA AA AA // ..хорошее продолжение
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA

/*

ТАБЛИЦА СЕКЦИЙ
Определяет, как файл будет загружен в память

*/

// .text
CP HE GF HI HE // ".text" > ASCII
AA AA AA // пустые байты

AA BA AA AA // виртуальный размер секции .text
AA BA AA AA // виртуальный адрес секции .text
AA AC AA AA // физический размер
AA AC AA AA // физическое смещение

AA AA AA AA // нет тут ничего 
AA AA AA AA
AA AA AA AA

CA AA AA GA // характеристики для секции .text - CODE EXECUTE READ

// .rdata
CP HC GE GB HE GB // .rdata ASCII
AA AA // null

AA BA AA AA // виртуальный размер секции .rdata
AA CA AA AA // виртуальный адрес секции .rdata
AA AC AA AA // физический размер
AA AE AA AA // физическое смещение

AA AA AA AA // пустые байты
AA AA AA AA 
AA AA AA AA 

EA AA AA EA // характеристики - INITIALIZED READ

// .data
CP GE GB HE GB // .data ASCII
AA AA AA // null

AA BA AA AA // виртуальный размер секции .data
AA DA AA AA // виртуальный адрес секции .data
AA AC AA AA // физический размер
AA AG AA AA // физ. смещение

AA AA AA AA // пустые байты 
AA AA AA AA 
AA AA AA AA

EA AA AA MA // характеристики - DATA READ WRITE (data readable writeable)

AA AA AA AA AA AA AA AA AA AA // пустой ужас
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA

/*

КОД
Непосредственно то, что будет исполняться

*/

// команды мы можем взять с www.wctsite.tk/code

GK	AA // команда PUSH с оп-кодом Ibss (в данном случае равен 0), операнд равен одному байту
GI	AA DA EA AA // команда PUSH с оп-кодом Ivs (переход на адрес EADAAAw), операнд равен 4 байтам
GI	BH DA EA AA // ^ (переход на адрес EADABHw), 4 байта
GK	AA // push AAw (0)
OO	BF   HA CA EA AA // команда CALL, вызов процедуры MessageBox по адресу EACAHAw
GK	AA // push AAw (0)
OO	BF   GI CA EA AA // команда CALL, вызов процедуры MessageBox по адресу EACAGIw

// пустые байты

AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA 

/*

ИМПОРТ
Связь между EXE и DLL

*/

// ExitProcess
DM CA AA AA // CADMw -> CAEMw, 0

AA AA AA AA // null
AA AA AA AA

HI CA AA AA // -> kernel32.dll
GI CA AA AA // -> CAEMw, 0

// MessageBoxA
EE CA AA AA // CAEEw -> CAFKw, 0

AA AA AA AA // null
AA AA AA AA

IF CA AA AA // -> user32.dll
HA CA AA AA // CAFKw, 0

AA AA AA AA // пустые байты
AA AA AA AA 
AA AA AA AA 
AA AA AA AA 
AA AA AA AA

EM CA AA AA AA AA AA AA // образует структуру MessageBoxA
FK CA AA AA AA AA AA AA // образует структуру ExitProcess

AA AA EF HI GJ HE FA HC GO GD GF HD HD AA // ASCII: ExitProcess, 0

AA AA EN GF HD HD GB GH GF EC GO HI EB AA // ASCII: MessageBoxA, 0

EM CA AA AA AA AA AA AA FK CA AA AA AA AA AA AA // ^
GL GF HC GP GF GM DD DC CP GE GM GM AA // ASCII: kernel32.dll, 0
HF HD GF HC DD DC CP GE GM GM AA // ASCII: user32.dll, 0

// пустые байты

AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA

/*

ДАННЫЕ
Информация, которая необходима коду программы

*/

FH GD HE CA FA EF CA HA HC GO GH HC GB GN CA GF HI GB GN HA GM GF AA // ASCII-данные: "Wct PE program example",0
EI GF GM GM GO CA HH GO HC GM GE CB AA // ASCII: "Hello world!",0

// пустые байты

AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA 
AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA AA
AA

// Конец программы.
// Спасибо за внимание!
// www.wctsite.tk
