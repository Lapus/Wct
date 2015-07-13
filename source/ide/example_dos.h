/* MZ заголовок, запускать в DOS-е */

EN FK // MZ заголовок (ASCII: MZ)
LN AA // Кол-во байтов в последнем блоке программы, которые будут использованы
AB AA // Кол-во блоков в файле, которые являются частью EXE файла
AB AA // Кол-во релокационных входов хранящихся после заголовка
AC AA // Кол-во параграфов в заголовке
BA AA // Кол-во параграфов дополнительной памяти которые нужны программе
BA AA // Максимальное кол-во параграфов дополнительной памяти
AK AA // Родственное значение сегмента стака
AA AB // Начальное значение SP регистра
AA AA // Сумма "слов"
AA AA // Начальное значение IP регистра
AA AA // Начальное значение СS регистра
BM AA // Смещение первого элемента релокации в файле
AA AA // Наложенное число

/* Конец заголовка */

Af AA aa aa 	// кладем в стек 0

Gk AA ao kb     // вынимаем значение из стека в fs
Li aj aa 	// помещаем в ax значение из data_segment
Ip ni    	// копируем значение в ds из ax
Ip ma    	// перемещаем в es значение ax

Li bd aa 	// в ax помещаем число BDw
Mn ba		// прерывание BAw
Ge GG kb am ab	// помещаем в eAX двойное слово [fs:Edw*4]
GG kd aa aa	// копируем в двойное слово int43 значение из eax
Lp ag aa	// в регистр SI помещаем адрес TEXT

/* GOTOXY */

Pi fo aa	// вызов функции GOTOXY
Km 		// загружаем 1 байт в регистр al по адресу DS:SI 
Ai MA		// ставит нулевой флаг если результат равен нулю
He EN		// если флаг равен нулю, то переходим на EXIT

Dm ca		// сравниваем регистр al с числом CAw
Hf AM		// если нет нуля в регистре ZF после выполнения предыдущей операции, то выполняется условие перехода на @1

Ia AG Af aa al	// добавляем байты в [Y] (11 байт)
Mg AG Ae aa aa	// копируем байты в [X] (0 байт)
Pl PI		// прыжок на NEXT

/* @1 */

AO Lg Ma mb	// копируем без расширения знака значение регистра al в ax
Pa AD		// сдвиг всех битов AX на 3 разряда
Fg		// кладем в стек SI
Bp		// и еще DS

Mf DG aa aa	// загрузка первых двух байтов из si в регистр [int43]
Ab MG		// добавляем в si значение из ax

/* Вывод на экран */

Lj AI aa	// в регистр cx помещаем число 8

/* loo0 */

Km		// байт в al, адрес - ds:si
Ii MD 		// в регистр bl кладем значение из al (обратите внимание, размер регистров одинаковый)
Fb		// кладем в стек CX
Lj AI aa	// в cx помещаем 8

/* loo1 */

La CA		// копируем в al CAw
Na ND		// сдвиг всех битов bl на 1
Hd AC		// если CF=0 и нет переноса, прыжок на @@1
La NL		// в регистр AL кладем число NLw

/* @@1 */

Mn CJ		// прерывание CJw
Pc OE		// цикл на метку loo1
Fj		// вынимаем значение из стека и кладем в регистр cx

Cg OP Ag AF aa	// увеличиваем значение байта по адресу es:Y
Pi BN aa	// вызываем функцию GOTOXY
Pc PC		// зацикливаемся на loo0

Bo		// вынимаем значение из стека в ds
Fp		// и в si
Ia AG AE aa ai	// добавляем 8 байтов в X
Ia CP AF aa ai	// вычитаем 8 байтов из Y
Pl KL		// прыгаем на NEXT

/* exit */

Da PE		// обнуляем регистр ah
Mn BG		// прерывание BGw
Li AD aa	// в регистр ax кладем Dw
Mn BA		// прерывание BAw
Le EM		// в регистр ah помещаем EMw
Mn CB		// прерывание CBw

/* gotoxy */

Ga		// размещение в стеке регистров общего назначения в следующей последовательности: ax, cx, dx, bx, sp, bp, si, di
Le AC		// в регистр ah помещаем 2
DB NL CG IL BG AE AA // в dx кладем двойное слово по адресу es:XY
Mn BA		// прерывание BAw
Gb		// извлечение из стека регистров общего назначения di, si, bp, sp, bx, dx, cx, ax
Md		// выходим из CALL

/* инфа */

Aa aa aa aa	// резервирование
Aa aa aa aa	// ^^^^^^^^^^^^^^

Aa		// 0
Ad		// 3

FH GD HE CA DN CJ AA // ASCII: "Wct =)",0 // TEXT