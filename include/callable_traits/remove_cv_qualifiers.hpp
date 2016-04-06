/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_REMOVE_CV_QUALIFIERS_HPP
#define CALLABLE_TRAITS_REMOVE_CV_QUALIFIERS_HPP

#include <callable_traits/detail/utility.hpp>
#include <callable_traits/no_sfinae/remove_cv_qualifiers.hpp>

namespace callable_traits {

    namespace detail {

        template<int i = 0>
        struct remove_cv_qualifiers_error {
			static_assert(i != 0,
				"callable_traits::remove_cv_qualifiers<T> is not a meaningful operation for this T.");
        };
    }

    template<typename T>
    using remove_cv_qualifiers = detail::fail_if_invalid<
		no_sfinae::remove_cv_qualifiers<T>,
		detail::remove_cv_qualifiers_error<>
	>;
}

#endif
