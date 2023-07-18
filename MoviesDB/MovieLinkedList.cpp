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

Movie^ MovieLinkedList::Head() // ������ ������
{
	return head;
}

Movie^ MovieLinkedList::Tail() // ����� ������
{
	return tail;
}

void MovieLinkedList::AddMovie(Movie^ mov) // ���������� ������
{
	if (head == nullptr) // ��� ������ ������
	{
		head = mov;
		tail = mov;
		return;
	}
	else // ���� ��������� > 1
	{
		tail->Next = mov;
		tail = mov;
		tail->Next = nullptr;
		return;
	}
}

void MovieLinkedList::DeleteMovie(int movIndex) // �������� ������
{
	if (movIndex == 0) { // �������� ������
		if (head == tail) { // ������� � ������ 1
			head = nullptr;
			tail = nullptr;
			return;
		}
		else { // ��������� > 1
			head = head->Next;
			return;
		}
	}
	int i = 1;
	Movie^ current = head; // ������ ������
	
	while (current->Next != tail && i < movIndex) { // ������ �� ������� ��������
		current = current->Next;
		i += 1;
	}
	if (current->Next == tail) { // ���� ��������� ������� �������� �������
		current->Next = nullptr;
		tail = current;
		return;
	}
	current->Next = current->Next->Next; // �������� ��������
}

void  MovieLinkedList::EditMovie(Movie^ movie, String^ _title, String^ _posterPath,  
	String^ _annotation, String^ _genre, int _raiting, DateTime _realeaseDate) // �������������� ��������
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
	if (!System::IO::File::Exists(path)) return false;  // �������� ������������� ����������
	if (!path->EndsWith("csv")) return false; // �������� ����������

	try // �������� ������ ������
	{
		StreamReader^ test = gcnew StreamReader(path, System::Text::Encoding::GetEncoding(1251));
		test->Close();
	}
	catch (IOException^) // ��������� ����������
	{
		return false;
	}

	StreamReader^ reader = gcnew StreamReader(path, System::Text::Encoding::GetEncoding(1251)); // ����� ������

	head = nullptr; // ������
	tail = nullptr; // �����
	// ��������� ���������� �����
	String^ str;
	cli::array<System::String^>^ row;
	String^ tempTitle; 
	String^ tempGenre;
	DateTime tempRealeaseDate; 
	String^ tempPosterPath;
	String^ tempAnnotation;
	int tempRating;


	while (str = reader->ReadLine()) // ���� � ����� �������� ������������� ������
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
	reader->Close(); // �������� �����
	return true; // �������� ����������
}

bool MovieLinkedList::SaveBase(String^ path)
{
	if (!path->EndsWith("csv")) return false; // �������� ���������� �����

	try // �������� ����������� ������
	{
		StreamWriter^ test = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding(1251));
		test->Close();
	}
	catch (IOException^) // ��������� ����������
	{
		return false; // ���������� ����������
	}

	StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding(1251)); // ����� ��� ������
	Movie^ node = head; // ������ ������ ��� ������
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

		node = node->Next; // ������� � ���� ���� ������
	}
	writer->Close(); // ��������� �����

	return true; // �������� ����������
}

List<Movie^>^ MovieLinkedList::Find(String^ title) // ����� �� ��������
{
	List<Movie^>^ lst = gcnew List<Movie^>; // ���� ��� ����������
	Movie^ current = head; // ������ ������
	while (current != nullptr) {
		if (current->Title->ToLower()->Contains(title->ToLower()) == true) // �������� � ������� ��������
		{
			lst->Add(current); // ���������� ����������
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::Find(int raitingFrom, int raitingTo) // ����� �� ��������
{
	List<Movie^>^ lst = gcnew List<Movie^>; // ���� ��� ����������
	Movie^ current = head; // ������ ������
	while (current != nullptr) {
		if (raitingFrom <= current->Rating && current->Rating <= raitingTo)
		{
			lst->Add(current); // ���������� ����������
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::FindbyGenre(String^ genre) // ����� �� �����
{
	List<Movie^>^ lst = gcnew List<Movie^>; // ���� ��� ����������
	Movie^ current = head; // ������ ������
	while (current != nullptr) {
		if (current->Genre->Contains(genre) == true)
		{
			lst->Add(current); // ���������� ����������
		}
		current = current->Next;
	}
	return lst;
}

List<Movie^>^ MovieLinkedList::GetMovies() // ��������� ������ ��� ������ � lisbox
{ 
	List<Movie^>^ result = gcnew List<Movie^>(); // ���� ��� ����������
	Movie^ cur = head; // ������ ������

	while (cur != nullptr) // � ����� ��������� �������� � ����
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