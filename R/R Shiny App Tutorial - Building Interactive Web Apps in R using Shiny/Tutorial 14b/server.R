library(shiny)

shinyServer(function(input, output) {
  dataset <- reactive({
    switch(input$datasets,
           "iris" = iris,
           "mtcars" = mtcars,
           "trees" = trees)
  })

  output$title1 <- renderText(paste("Structure of the dataset", input$datasets))

  output$str <- renderPrint(str(dataset()))

  output$title2 <- renderText({
    input$action
    # For the first time, don't show this part.
    # Once click the button, show it.
    if (input$action == 0) {
      return()
    } else {
      isolate(paste("First", input$obs, "observations of the dataset",
                    input$datasets))
    }
  })

  output$view <- renderTable({
    input$action

    if (input$action == 0) {
      return()
    } else {
      isolate(head(dataset(), n = input$obs))
    }
  })
})
