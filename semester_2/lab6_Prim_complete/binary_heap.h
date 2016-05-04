#ifndef _BINARY_HEAP_
	#define _BINARY_HEAP_
	#define _BINARY_HEAP_LOW_MEM_ 0
	typedef _heap {
		void* array; // указатель на область памяти выделенную под кучу
		//TODO придумать универсальную замену по ключу (новые элементы индексируются неверно после удаления элементов из кучи, нет проверки на наличия элемента с данным индексом в массиве)
		size_t* index; // текущее расположение элементов (в позиции n хранится положение n-ного добавленного элемента)
		size_t count; // текущее кол-во элементов в куче
		size_t countMAX; // размер памяти выделенной под кучу
		size_t size; // размер одного элемента
		int (*comparator)(const void*, const void*); // функция сравнения элементов кучи
	}heap;

	/**
	 * создание пустой структуры "бинарная куча"(выделяется)
	 * @param  countMAX 	максимальное кол-во элементов
	 * @param  size  			размер одного элемента
	 * @param  comparator	функция сравнения (strcmp подобные)
	 * @return      			указатель на структуру "бинарная куча", если каждый из параметров ненулевой
	 *                    NULL	иначе
	 */
	heap* make_heap(size_t countMAX, size_t size, int (*comparator)(const void*, const void*));

	/**
	 * Построение бинарной кучи на массиве
	 * @param		array				указатель массив, который нужно перестроить в бинарную кучу
	 *                  		(при использовании этого массива не через функционал кучи, свойства кучи могут нарушиться)
	 * @param		count				кол-во элементов в массиве
	 * @param		countMAX		кол-во элементов, которое может поместиться в массиве
	 * @param		size				размер элемента массива
	 * @param		comparator	функция сравнения (strcmp подобные)
	 * @return							указатель на структуру "бинарная куча", если каждый из параметров ненулевой
	 *                      NULL	иначе
	 */
	heap* build_heap(void* array, size_t count, size_t countMAX, size_t size, int (*comparator)(const void*, const void*));
	
	/**
	 * добавление элемента в кучу
	 * @param 	bheap указатель на бинарную кучу
	 * @param 	new   указатель на новый элемент
	 * @return				1 если получилось добавить
	 *                0 иначе
	 */
	char insert(heap* bheap, void* new);

	/**
	 * удаление максимального элемента
	 * @param 	bheap указатель на бинарную кучу
	 * @return				указатель на максимальный элемент внутри кучи (будет правильным до следующего insert), если куча не пуста
	 *                NULL	иначе
	 */
	void* get_max(heap* bheap);

	/**
	 * удаление максимального элемента
	 * @param 	bheap указатель на бинарную кучу
	 * @return				указатель на максимальный элемент (скопированный в новую выделенную память), если куча не пуста
	 *                NULL	иначе
	 */
	void* extract_max(heap* bheap);

	/**
	 * проверка кучи на пустоту
	 * @param  bheap указатель на бинарную кучу
	 * @return       1 если пуста
	 *               0 иначе
	 */
	char isEmpty(heap* bheap);

	//TODO замена по индексу


#endif