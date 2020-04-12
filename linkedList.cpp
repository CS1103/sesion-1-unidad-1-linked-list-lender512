//
// Created by utec on 4/11/20.
//

#include "linkedList.h"


utec::first::linked_list_t::linked_list_t(const utec::linked_list_t& other) {
	head_ = other.head_;
	tail_ = other.tail_;
	size_ = other.size_;
}

utec::linked_list_t& utec::first::linked_list_t::operator=(const utec::linked_list_t& other) {
	head_ = other.head_;
	tail_ = other.tail_;
	size_ = other.size_;

	return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t&& other) noexcept {

}

utec::linked_list_t& utec::first::linked_list_t::operator=(utec::linked_list_t&& other) noexcept {

	// TO DO
	return *this;
}

utec::first::linked_list_t::~linked_list_t() {

}

void utec::first::linked_list_t::push_front(int value) {

	/*
	auto node = new node_t{value, head_}
	head_ = node;
	*/
	head_ = new node_t{ value, head_ };
	if (tail_ == nullptr) tail_ = head_;
	size_++;

}

void utec::first::linked_list_t::push_back(int value) {
	
	auto node = new node_t{ value, nullptr };
	if (head_ == nullptr) head_ = node;
	else {
		tail_->next_ = node;
	}
	tail_ = node;
	
	size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {
	if (index == 0) {
		//hace pushfront
		head_ = new node_t{ value, head_ };
		if (tail_ == nullptr) tail_ = head_;
		size_++;
	}
	else if (index == size_ - 1) {
		//hace pushback
		auto node = new node_t{ value, nullptr };
		if (head_ == nullptr) head_ = node;
		else {
			tail_->next_ = node;
		}
		tail_ = node;

		size_++;
	}
	else {
		auto start = head_;
		for (int i = 0; i < index - 1; i++) {
			start = start->next_;
		}
		auto temp = start->next_;
		start->next_ = new node_t{ value, temp };
		//delete temp;
		size_++;
	}

}

void utec::first::linked_list_t::pop_front() {
	if (head_ == tail_) {
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}
	else {
		auto next = head_->next_;
		delete head_;
		head_ = next;
		size_--;
	}
}

void utec::first::linked_list_t::pop_back() {
	if (head_ == tail_) {
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}
	else {
		auto i = head_;
		while (i->next_->next_ != NULL) {
			i = i->next_;
		}
		delete tail_;
		tail_ = i;
		tail_->next_ = nullptr;
		size_--;
	}
}

void utec::first::linked_list_t::erase(size_t index) {
	if (index >= size_) {
		std::cout << "fuera de rango";
	}
	else if (index == 0) {
		//hace popfront
		if (head_ == tail_) {
			delete head_;
			head_ = tail_ = nullptr;
			size_ = 0;
		}
		else {
			auto next = head_->next_;
			delete head_;
			head_ = next;
			size_--;
		}
	}
	else if (index == size_-1){
		//hace popback
		if (head_ == tail_) {
			delete head_;
			head_ = tail_ = nullptr;
			size_ = 0;
		}
		else {
			auto i = head_;
			while (i->next_->next_ != NULL) {
				i = i->next_;
			}
			delete tail_;
			tail_ = i;
			tail_->next_ = nullptr;
			size_--;
		}
	}
	else {
		auto start = head_;
		for (int i = 0; i < index - 1; i++) {
			start = start->next_;
		}
		auto temp = start->next_->next_;
		delete start->next_;
		start->next_ = temp;
		//delete temp;
		size_--;
	}
	
}

int& utec::first::linked_list_t::item(size_t index) {
	auto actual = head_;
	while (index--)
		actual = actual->next_;
	return actual->value_;
}

const int& utec::first::linked_list_t::item(size_t index) const {
	auto actual = head_;
	while (index--)
		actual = actual->next_;
	return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
	return size_;
}
