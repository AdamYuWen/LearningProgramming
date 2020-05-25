library(shiny)

shinyServer(
  function(input, output) {
    # Tutorial 07
    # There are {} inside of renderPlot().
    output$my_hist <- renderPlot({
      # The class of var is character, so change it to numeric.
      num_col <- as.numeric(input$var)
      # breaks: from 0 to the largest number
      #         If n bins, there are n + 1 ending points.
      #         l is length, means the number of breaks
      hist(iris[, num_col],
           breaks = seq(min(iris[, num_col]),
                        max(iris[, num_col]),
                        l = input$bins + 1),
           col = input$color,
           main = "Historgram of iris dataset",
           xlab = names(iris[num_col]))
    })

    # Tutorial 08
    output$my_summary <- renderPrint({
      summary(iris)
    })

    output$str <- renderPrint({
      str(iris)
    })

    output$data <- renderTable({
      num_col <- as.numeric(input$var)
      iris[num_col]
      # If the code likes the following line, the title is not included.
      # iris[, num_col]
    })
  }
)
