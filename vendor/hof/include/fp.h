#pragma once

#include <vector>
#include <variant>
#include <optional>

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
		template<class TError, class TSuccess>
		class Either
		{
		public:
			Either(const TError& left)
				: maybe(left) {}

			Either(const TSuccess& right)
				: maybe(right) {}

			Either& operator=(const Either& other) = delete;			
			
			void Match(void leftHandler(TError), void rightHandler(TSuccess)) 
			{
				std::get_if<TError>(&maybe) ? 
					leftHandler(std::get<TError>(maybe)) : rightHandler(std::get<TSuccess>(maybe));
			}

			template<class T>
			void Match(void errorHandler(TError, T), void successHandler(TSuccess, T), T state)
			{
				std::get_if<TError>(&maybe) ?
					errorHandler(std::get<TError>(maybe), state) : successHandler(std::get<TSuccess>(maybe), state);
			}

			Either<TError, TSuccess> Match(Either<TError, TSuccess> errorHandler(TError), Either<TError, TSuccess> successHandler(TSuccess))
			{
				return std::get_if<TError>(&maybe) ?
					errorHandler(std::get<TError>(maybe)) : successHandler(std::get<TSuccess>(maybe));
			}

			template<class T>
			T Match(T errorHandler(TError), T successHandler(TSuccess))
			{
				return std::get_if<TError>(&maybe) ?
					errorHandler(std::get<TError>(maybe)) : successHandler(std::get<TSuccess>(maybe));
			}	

			template<class T>
			Either<TError, TSuccess> Map(TSuccess fn(TSuccess, T), T val)
			{
				return std::get_if<TError>(&maybe) ? std::get<TError>(maybe) 
					: (Either<TError, TSuccess>)fn(std::get<TSuccess>(maybe), val);
			}

			template<class T>
			Either<TError, TSuccess> Map(TSuccess fn(TSuccess, T), bool pred(T), T val)
			{
				if (!pred(val))
				{
					return TError();
				}

				return std::get_if<TError>(&maybe) ? std::get<TError>(maybe)
					: (Either<TError, TSuccess>)fn(std::get<TSuccess>(maybe), val);
			}
		private:
			std::variant<TError, TSuccess> maybe;
		};

		template<class TOptional>
		class Optional
		{
		public:
			Optional()
				: opt(std::nullopt) {}

			Optional(const TOptional& opt)
				: opt(opt) {}

			void Match(void optionalHandler(TOptional))
			{
				if (opt.has_value())
				{
					optionalHandler(opt.value());
				}
			}
		private:
			std::optional<TOptional> opt;
		};
	}
}