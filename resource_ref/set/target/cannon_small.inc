{selector
	{type "cannon_small"}
	
	{group
		{select {class armoredcar}}
		{select {class tank_light}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{ignore {class airborne}}
		{sort {class tank_medium}}
		{sort {class tank_heavy}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class car_cannon} {weapon}}
		{select {class car_bullet} {weapon}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort distance}
	}
	{group
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{sort {attacking}}
		{sort distance}
	}
}
