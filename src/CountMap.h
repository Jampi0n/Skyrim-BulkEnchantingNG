namespace BulkEnchanting {
	using Count = int32_t;

	template<typename T>
	class CountMap {
		/// <summary>
		/// Stores counts for each keys.
		/// Compared to a regular map, it defaults to 0 if the key is not found and simplifies arithmetic operations between CountMaps.
		/// </summary>
		/// <typeparam name="T">Key type.</typeparam>
	private:
		std::map<T, Count> _countMap;
		T def;
	public:
		void modItem(T item, Count num) {
			/// <summary>
			/// Modifies the count of the key.
			/// </summary>
			/// <param name="item"></param>
			/// <param name="num"></param>
			if (num == 0) {
				return;
			}
			auto it = _countMap.find(item);
			if (it == _countMap.end()) {
				_countMap.insert(std::pair<T, Count>(item, num));
			} else {
				Count newNum = _countMap.at(item) + num;
				_countMap.erase(item);
				if (newNum != 0) {
					_countMap.insert(std::pair<T, Count>(item, newNum));
				}
			}
		}

		Count getItem(T item) {
			/// <summary>
			/// Returns the count of the key.
			/// </summary>
			/// <param name="item"></param>
			/// <returns></returns>
			auto it = _countMap.find(item);
			if (it == _countMap.end()) {
				return 0;
			} else {
				return _countMap.at(item);
			}
		}

		bool hasItem(T item) {
			/// <summary>
			/// Returns true, if the key has a positive count.
			/// </summary>
			/// <param name="item"></param>
			/// <returns></returns>
			return getItem(item) > 0;
		}

		CountMap<T> mul(Count factor) {
			/// <summary>
			/// Returns a new CountMap with multiplied counts.
			/// </summary>
			/// <param name="factor"></param>
			/// <returns></returns>
			CountMap<T> newMap;
			if (factor != 0) {
				for (auto const& [key, val] : _countMap) {
					newMap.modItem(key, val * factor);
				}
			}
			return newMap;
		}

		CountMap<T> add(CountMap<T>* other) {
			/// <summary>
			/// Returns a new CountMap with added counts.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			CountMap<T> newMap;
			for (auto const& [key, val] : _countMap) {
				newMap.modItem(key, val);
			}
			for (auto const& [key, val] : other->_countMap) {
				newMap.modItem(key, val);
			}
			return newMap;
		}

		CountMap<T> sub(CountMap<T>* other) {
			/// <summary>
			/// Returns a new CountMap with subtracted counts.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			return add(&other->mul(-1));
		}

		std::map< T, Count>* getMap() {
			/// <summary>
			/// Returns the underlying map to iterate over the entries.
			/// Keys with counts of 0 are never in the map.
			/// </summary>
			/// <returns></returns>
			return &_countMap;
		}

		void reset() {
			/// <summary>
			/// Removes all keys from the map.
			/// </summary>
			_countMap.clear();
		}
		bool isSingular() {
			/// <summary>
			/// Returns true, if the map contains only a single key with count 1.
			/// </summary>
			/// <returns></returns>
			bool singular = _countMap.size() == 1;
			if (singular) {
				for (auto const& [key, val] : _countMap) {
					if (val == 1) {
						return true;
					}
					return false;
				}
			}
			return false;
		}

		T getSingular() {
			/// <summary>
			/// If the map is singular, it returns the singular key.
			/// </summary>
			/// <returns></returns>
			bool singular = _countMap.size() == 1;
			if (singular) {
				for (auto const& [key, val] : _countMap) {
					if (val == 1) {
						return key;
					}
					return def;
				}
			}
			return def;
		}
	};
}