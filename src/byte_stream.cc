#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : stream(), capacity_( capacity ), used_capacity_(0), total_pushed_(0), total_popped_(0) {}

bool Writer::is_closed() const
{
  // Your code here.
  return closed_;
}

void Writer::push( string data )
{
  // Your code here.
  if (error_ || closed_) return;
  uint64_t pushing_size_ = min(capacity_ - used_capacity_, data.length());
  used_capacity_ += pushing_size_;
  total_pushed_ += pushing_size_;
  stream.append(data.substr(0, pushing_size_));
  return;
}

void Writer::close()
{
  // Your code here.
  closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - used_capacity_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return total_pushed_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return closed_ && (used_capacity_ == 0);
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return total_popped_;
}

string_view Reader::peek() const {
  return stream;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if (used_capacity_ == 0) return;
  uint64_t popping_size_ = min(used_capacity_, len);
  used_capacity_ -= popping_size_;
  total_popped_ += popping_size_;

  stream.erase(0, popping_size_);
  return;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return used_capacity_;
}