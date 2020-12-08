#pragma once

#include <vector>

namespace Functional
{
	namespace HOF
	{
		template<class T>
		void ForEach(void fn(T ele), std::vector<T> seq)
		{
			size_t len = seq.size();

			for (int i = 0; i < len; i++)
			{
				fn(seq[i]);
			}
		}

		template<class T, class U>
		std::vector<U> Map(U fn(T ele), std::vector<T> seq)
		{
			std::vector<U> res;
			size_t len = seq.size();
			for (int i = 0; i < len; i++)
			{
				res.push_back(fn(seq[i]));
			}

			return res;
		}

		template<class T>
		std::vector<T> Filter(bool predicate(T ele), std::vector<T> seq)
		{
			std::vector<T> res;
			size_t len = seq.size();
			for (int i = 0; i < len; i++)
			{
				if (predicate(seq[i]))
				{
					res.push_back(seq[i]);
				}
			}

			return res;
		}

		template<class T>
		T Reduce(T fn(T first, T second), std::vector<T> seq)
		{
			T res = seq[0];
			size_t len = seq.size();
			for (int i = 1; i < len; i++)
			{
				res = fn(seq[i], res);
			}

			return res;
		}
	}
	
	namespace Type
	{
		template<class TL, class TR>
		class Either
		{
		public:
			Either(const TL& left)
				: left(left), isLeft(true) {}

			Either(const TR& right)
				: right(right), isLeft(false) {}

			Either& operator=(const Either& other) = delete;

			void Match(void leftHandler(TL), void rightHandler(TR)) 
			{
				isLeft ? leftHandler(left) : rightHandler(right);
			}

			template<class T>
			T Match(T leftHandler(TL), T rightHandler(TR))
			{
				return isLeft ? leftHandler(left) : rightHandler(right);
			}
		private:
			TL left;
			TR right;
			bool isLeft;
		};
	}
}