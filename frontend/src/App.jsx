import { useEffect, useState } from 'react';
import './App.css'

function App() {
  const [data, setData] = useState({ message: '', author: '' });
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const res = await fetch("http://localhost:18080/");
        if (!res.ok) {
          throw new Error(`HTTP error! status: ${res.status}`);
        }

        const json = await res.json();
        setData({
          message: json.message,
          author: json.author
        });
      } catch (err) {
        console.error("Fetch error:", err);
        setError("Failed to load data.");
      }
    };

    fetchData();
  }, []);

  return (
    <div>
      {error ? (
        <p>{error}</p>
      ) : (
        <>
          <h1>{data.message}</h1>
          <p>By {data.author}</p>
        </>
      )}
    </div>
  );
}

export default App
