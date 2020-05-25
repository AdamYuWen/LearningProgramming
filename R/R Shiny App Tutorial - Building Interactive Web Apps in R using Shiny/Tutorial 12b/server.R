library(shiny)

shinyServer(function(input, output) {
  dataset <- reactive({
    switch(input$dataset,
           "iris" = iris,
           "mtcars" = mtcars,
           "trees" = trees)
  })

  # paste function adds spaces.
  # It works for both character and numeric.
  output$title1 <- renderText(paste("Structure of the dataset", input$dataset))
  output$title2 <- renderText(paste("First", input$obs,
                                    "observatiosn of the dataset ",
                                    input$dataset))

  output$str <- renderPrint(str(dataset()))
  # obs was read as numeric.
  output$view <- renderTable({
    head(dataset(), n = input$obs)
  })
})
