#pragma once

#include "Movie.h"
using namespace System::Collections::Generic;

ref class MovieLinkedList
{
private:
	Movie^ head; // голова списка
	Movie^ tail; // хвост списка
public:
	MovieLinkedList() // конструктор односвязного списка
	{
		head = nullptr;
		tail = nullptr;
	}
	Movie^ Head(); // голова списка
	Movie^ Tail(); // хвост списка
	bool ReadBase(System::String^ path); // удаление БД
	bool SaveBase(System::String^ path); // сохранение БД
	void AddMovie(Movie^ movie); // добавление фильма
	void DeleteMovie(int MovIndex); //  удаление фильма
	void EditMovie(Movie^ movie, System::String^ _title, System::String^ _posterPath,
		System::String^ _annotation, System::String^ _genre, int _raiting, System::DateTime _realeaseDate); // редактирование фильма
	List<Movie^>^ Find(System::String^ title); // поиск по названию
	List<Movie^>^ Find(int raitingFrom, int raitingTo); // поиск по рейтингу
	List<Movie^>^ FindbyGenre(System::String^ genre); // Поиск по жанру
	List<Movie^>^ GetMovies(); // Фильмы для вывода в ListBox
};

