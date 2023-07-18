#define _CRT_SECURE_NO_WARNINGS
#include "MovieLinkedList.h"
#include "Movie.h"
#include <ctime>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>

using msclr::interop::marshal_as;
using namespace System::IO;
using namespace System;

Movie^ MovieLinkedList::Head() // голова списка
{
	return head;
}

Movie^ MovieLinkedList::Tail() // хвост списка
{
	return tail;
}

void MovieLinkedList::AddMovie(Movie^ mov) // добавление фильма
{
	if (head == nullptr) // при пустом списке
	{
		head = mov;
		tail = mov;
		return;
	}
	else // если элементов > 1
	{
		tail->Next = mov;
		tail = mov;
		tail->Next = nullptr;
		return;
	}
}

void MovieLinkedList::DeleteMovie(int movIndex) // удаление фильма
{
	if (movIndex == 0) { // удаление головы
		if (head == tail) { // элемент в списке 1
			head = nullptr;
			tail = nullptr;
			return;
		}
		else { // элементов > 1
			head = head->Next;
			return;
		}
	}
	int i = 1;
	Movie^ current = head; // голова списка
	
	while (current->Next != tail && i < movIndex) { // проход до нужного элемента
		current = current->Next;
		i += 1;
	}
	if (current->Next == tail) { // ≈сли удал€емый элемент €вл€етс€ хвостом
		current->Next = nullptr;
		tail = current;
		return;
	}
	current->Next = current->Next->Next; // удаление элемента
}

void  MovieLinkedList::EditMovie(Movie^ movie, String^ _title, String^ _posterPath,  
	String^ _annotation, String^ _genre, int _raiting, DateTime _realeaseDate) // редактирование карточки
{
	movie->Title = _title;
	movie->Genre = _genre;
	movie->Annotation = _annotation;
	movie->Rating = _raiting;
	movie->PosterPath = _posterPath;
	movie->RealeaseDate = _realeaseDate;
}

bool MovieLinkedList::ReadBase(String^ path)
{
	if (!System::IO::File::Exists(path)) return false;  // проверка существовани€ директории
	if (!path->EndsWith("csv")) return false; // проверка расширени€

	try // проверка потока чтени€
	{
		StreamReader^ test = gcnew StreamReader(path, System::Text::Encoding::GetEncoding(1251));
		test->Close();
	}
	catch (IOException^) // обработка исключени€
	{
		return false;
	}

	StreamReader^ reader = gcnew StreamReader(path, System::Text::Encoding::GetEncoding(1251)); // поток чтени€

	head = nullptr; // голова
	tail = nullptr; // хвост
	// временные переменные полей
	String^ str;
	cli::array<System::String^>^ row;
	String^ tempTitle; 
	String^ tempGenre;
	DateTime tempRealeaseDate; 
	String^ tempPosterPath;
	String^ tempAnnotation;
	int tempRating;


	while (str = reader->ReadLine()) // пока в файле остались непрочитанные строки
	{
		row = str->Split('|');
		tempTitle = row[0];
		tempGenre = row[1];
		tempPosterPath = row[2];
		tempAnnotation = row[3];
		tempRating = Convert::ToInt32(row[4]);
		tempRealeaseDate = DateTime(Convert::ToInt32(row[5]), Convert::ToInt32(row[6]), Convert::ToInt32(row[7]));
		this->AddMovie(gcnew Movie(tempTitle, tempPosterPath, tempGenre, tempAnnotation, tempRealeaseDate, tempRating));
	}
	reader->Close(); // закрывем поток
	return true; // успешное завершение
}

bool MovieLinkedList::SaveBase(String^ path)
{
	if (!path->EndsWith("csv")) return false; // проверка рашсирени€ файла

	try // тестовое подключение потока
	{
		StreamWriter^ test = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding(1251));
		test->Close();
	}
	catch (IOException^) // обработка исключени€
	{
		return false; // неуспешное завершение
	}

	StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding(1251)); // поток дл€ записи
	Movie^ node = head; // голова списка дл€ записи
	while (node != nullptr)
	{
		writer->Write(node->Title + "|");
		writer->Write(node->Genre + "|");
		writer->Write(node->PosterPath + "|");
		writer->Write(node->Annotation + "|");
		writer->Write(node->Rating + "|");
		writer->Write(node->RealeaseDate.Year + "|");
		writer->Write(node->RealeaseDate.Month + "|");
		writer->Write(node->RealeaseDate.Day + "\n");

		node = node->Next; // переход к след узлу списка
	}
	writer->Close(); // закрываем поток

	return true; // успешное завершение
}

List<Movie^>^ MovieLinkedList::Find(String^ title) // ѕоиск по названию
{
	List<Movie^>^ lst = gcnew List<Movie^>; // лист дл€ результата
	Movie^ current = head; // голова списка
	while (current != nullptr) {
		if (current->Title->ToLower()->Contains(title->ToLower()) == true) // приводим к нижнему регистру
		{
			lst->Add(current); // добавление совпадени€
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::Find(int raitingFrom, int raitingTo) // ѕоиск по рейтингу
{
	List<Movie^>^ lst = gcnew List<Movie^>; // лист дл€ результата
	Movie^ current = head; // голова списка
	while (current != nullptr) {
		if (raitingFrom <= current->Rating && current->Rating <= raitingTo)
		{
			lst->Add(current); // добавление совпадени€
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::FindbyGenre(String^ genre) // ѕоиск по жанру
{
	List<Movie^>^ lst = gcnew List<Movie^>; // лист дл€ результата
	Movie^ current = head; // голова списка
	while (current != nullptr) {
		if (current->Genre->Contains(genre) == true)
		{
			lst->Add(current); // добавление совпадени€
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::GetMovies() // ѕолучение списка дл€ вывода в lisbox
{ 
	List<Movie^>^ result = gcnew List<Movie^>(); // лист дл€ результата
	Movie^ cur = head; // голова списка

	while (cur != nullptr) // в цикле добавл€ем элементы в Ћист
	{
		result->Add(cur);
		cur = cur->Next;
	}
	return result;
}

bool MovieLinkedList::IsMovExist(Movie^ mov) {
	Movie^ cur = head;
	while (cur != nullptr) {
		if (cur->Title->Equals(mov->Title) && cur->RealeaseDate.Equals(mov->RealeaseDate)) {
			return true;
		}
		cur = cur->Next;
	}
	return false;
}