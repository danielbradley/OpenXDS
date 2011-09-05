package org.openxds.adt.std.comparitors;

import org.openxds.adt.IComparitor;

public class IntegerComparitor<K> implements IComparitor<K> {

	public int compare(K a, K b) throws IllegalArgumentException
	{
		try
		{
			Integer _a = (Integer) a;
			Integer _b = (Integer) b;
			
			return _a - _b;
		}
		catch ( Exception ex )
		{
			try
			{
				int _a = Integer.valueOf( a.toString() );
				int _b = Integer.valueOf( b.toString() );
			
				return _a - _b;
			} catch ( Exception ex2 ) {
				throw new IllegalArgumentException();
			}
		}
	}
}
