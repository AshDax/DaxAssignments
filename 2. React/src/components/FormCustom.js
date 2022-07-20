import axios from 'axios';
import Button from 'react-bootstrap/Button';
import Form from 'react-bootstrap/Form';

const postURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs'


const FormCustom = () => 
{
    const handleFormData = (e) =>{
      e.preventDefault();
        const inputData = new FormData(e.target)
        const formDataObj = Object.fromEntries(inputData.entries())
        const formData = {
                "title": formDataObj.title,
                "description": formDataObj.description,
                "author": formDataObj.author,
                "reading_time": formDataObj.time
        }
        axios.post(postURL,formDataObj,
            {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
                },
                    
            })
        }

        return(  
          
            <Form onSubmit={handleFormData} className='container'>
            <Form.Control size="sm" type="text" placeholder="title" name='title' />
              <br />
            <Form.Control type="text" placeholder="description" name='description' />
              <br />
            <Form.Control size="sm" type="text" placeholder="Author"  name='author'/>
              <br />
            <Form.Control size="sm" type="text" placeholder="time" name='reading_time' />
              <br />
            <Button  type='submit' variant="light">Submit</Button>
            </Form>
        )
}

export default FormCustom;