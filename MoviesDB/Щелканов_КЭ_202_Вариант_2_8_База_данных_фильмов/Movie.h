#pragma once

ref class Movie {
public:
	System::String^ Title; // название
	System::String^ PosterPath; // путь к постеру
	System::String^ Genre; // жанр
	System::String^ Annotation; // аннтоация
	System::DateTime RealeaseDate; // дата релиза
	int Rating; // рейтинг
	Movie ^Next; // ссылка на след элемент
	Movie(System::String^ title, System::String^ posterpath, System::String^ genre, 
		System::String^ annotation, System::DateTime realesadate, int rating) // конструктор класса
	{
		this->Title = title;
		this->Genre = genre;
		this->PosterPath = posterpath;
		this->Annotation= annotation;
		RealeaseDate = realesadate;
		Rating = rating;
		Next = nullptr;
	}
};


