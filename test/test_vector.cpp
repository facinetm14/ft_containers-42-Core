/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:46:33 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/06 19:46:33 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>
#include "../vector/vector.hpp"

int     main()
{
    // ---------------- testing constructors ------------------------
    {
        test_head("constructors");
        std::vector<int> v;
        ft::vector<int> v1;
        //assert(*(v.begin()), *(v1.begin()));
        //v1.begin();
    }

    return (0);
}