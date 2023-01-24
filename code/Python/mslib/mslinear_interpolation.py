import numpy as np

# Functions
def slice_by_min_max(values, min, max):
    num_value = values.size

    under_min_end_index = 0
    for i in range(0, num_value):
        x = values[i]
        if (min <= x):
            under_min_end_index = i
            break

    over_max_start_index = num_value
    for i in reversed(range(0, num_value)):
        x = values[i]
        if (x <= max):
            over_max_start_index = i+1
            break

    under_min_values = values[0:under_min_end_index]
    in_range_values = values[under_min_end_index:over_max_start_index]
    over_max_values = values[over_max_start_index:num_value]

    return under_min_values, in_range_values, over_max_values


def cal_range_indexes(ref_xs, xs):
    num_ref_xs = ref_xs.size
    num_xs = xs.size

    search_start_index = 0

    range_indexes = np.zeros(num_xs, dtype=int)
    for i in range(0, num_xs):
        x = xs[i]

        for j in range(search_start_index, num_ref_xs-1):
            min_x = min(ref_xs[j], ref_xs[j+1])
            max_x = max(ref_xs[j], ref_xs[j+1])
            
            if min_x <= x <= max_x:
                range_indexes[i] = j
                search_start_index = j+1
                break
    
    return range_indexes


def cal_interpolation_ys(xs,ys,interpolation_xs):
    min_x = xs[0]
    max_x = xs[-1]

    # slice interpolation xs
    under_min_xs, in_range_xs, over_max_xs = slice_by_min_max(interpolation_xs,min_x,max_x)

    #interpolattion
    num_interpolation_datas = interpolation_xs.size

    index = 0
    interpolation_ys = np.zeros(num_interpolation_datas)

    # under min interpolation
    x1 = xs[0]
    y1 = ys[0]
    x2 = xs[1]
    y2 = ys[1]
    under_min_slope = (y2 - y1) / (x2 - x1)
    for interpolation_x in under_min_xs:
        interpolation_y = y1 + under_min_slope *(interpolation_x - x1)
        
        interpolation_ys[index] = interpolation_y
        index = index+1

    # in range interpolation
    range_indexes = cal_range_indexes(xs,in_range_xs)

    num_in_range_datas = in_range_xs.size
    for i in range(0, num_in_range_datas):
        interpolation_x = in_range_xs[i]
        
        range_index = range_indexes[i]
        x1 = xs[range_index]
        y1 = ys[range_index]
        x2 = xs[range_index+1]
        y2 = ys[range_index+1]

        slope = (y2 - y1) / (x2 - x1)    
        interpolation_y = y1 + slope *(interpolation_x - x1)

        interpolation_ys[index] = interpolation_y
        index = index+1

    # over max interpolation
    num_data = xs.size
    x1 = xs[num_data-2]
    y1 = ys[num_data-2]
    x2 = xs[num_data-1]
    y2 = ys[num_data-1]

    over_range_slope = (y2 - y1) / (x2 - x1)
    for interpolation_x in over_max_xs:
        interpolation_y = y2 + over_range_slope * (interpolation_x - x2)
        
        interpolation_ys[index] = interpolation_y
        index = index+1

    return interpolation_ys