package org.openxds.adt.std.comparitors;

import org.openxds.adt.IComparitor;

public class LexicographicComparitor<K> implements IComparitor<K> {

	public int compare(K a, K b) throws IllegalArgumentException
	{
		String _a = a.toString();
		String _b = b.toString();

		return _a.compareTo( _b );
	}
}
