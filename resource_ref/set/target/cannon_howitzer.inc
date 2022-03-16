{selector
	{type "cannon_howitzer"}

	{group
		{ignore {class airborne}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort distance}
	}
	{group
		{select {class car}}
		{sort {weapon}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{select {class armoredcar}}
		{select {class car_cannon}}
		{select {class car_bullet}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class cannon_bullet}}
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{sort {class tank_light}}
		{sort {class tank_bullet}}
		{sort {class tank_medium}}
		{sort {class tank_heavy}}
		{sort {class car}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{sort {attacking}}
		{sort distance}
	}
}
